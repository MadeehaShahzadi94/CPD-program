/*********************************************************************************
* WEB422 â€“ Assignment 2
* I declare that this assignment is my own work in accordance with Seneca Academic Policy.
* No part of this assignment has been copied manually or electronically from any other source
* (including web sites) or distributed to other students.
*
* Name: Madeeha Shahzadi Student ID: 130638182 Date: June 16,2020
*
*
********************************************************************************/ 

let saleData = [];

let perPage = 10;
let page = 1;

$(function(){

    loadSaleData();

    $("#sale-table tbody").on("click","tr",function(e){
            e.preventDefault();
            var modal = $('#sale-modal');
            
            let tempData = saleData;
            let i = $(this).closest("tr").index();
            
            let clickedSale = tempData[i];
            
            var totalPrice = 0.0;
            clickedSale.items.forEach(element => {
                totalPrice += (element.price * element.quantity);
            });

            var newObjWithTotal = {
                total: totalPrice
            };

            var objWithTotal = _.assign({}, clickedSale, newObjWithTotal);
 
        
            let saleModelBodyTemplate = _.template(
                `<h4>Sale: <%- temp._id %></h4>
                <h4>Customer</h4>
                <strong>email: </strong><%- temp.customer.email %><br>
                <strong>age: </strong><%- temp.customer.age %><br>
                <strong>satisfaction: </strong><%- temp.customer.satisfaction %> / 5
                <br><br>
                <h4>Items: $<%- temp.total.toFixed(2) %></h4>
            
                <table class="table">
                <thead>
                <tr>
                    <th>Product Name</th> 
                    <th>Quantity</th> 
                    <th>Price</th>
                </tr>
                </thead>
                <tbody>
                    <% temp.items.forEach(e => { %>
                        <tr>
                            <td><%- e.name %></td>
                            <td><%- e.quantity %></td>
                            <td>$<%- e.price %></td>
                        </tr> 
                    <% }); %>
                </tbody>
                </table>
                `);
    
            
            let modalInfo = saleModelBodyTemplate({'temp': objWithTotal});
            modal.find('.modal-body').html(modalInfo);
            modal.modal('show');
         
    });

    // events for next/previous button
    $('#nextPage').on("click",function () {
        page++;
        loadSaleData();
    });

    $('#prevPage').on("click",function () {
        if(page > 1) {
            page--;
            loadSaleData();
        }
    });
});



function loadSaleData(){
    // update current page number
    $('#currentPage').text(page);

    let api = "https://mighty-ocean-95072.herokuapp.com/api/sales?page=" + page + "&perPage=" + perPage;

    fetch(api)
    .then(response => response.json())
    .then(json => {
        saleData = json;
        refreshMainTable(saleData); 
    });

}


function refreshMainTable(data){

    $("sale-table tbody").empty();
    let saleTableTemplate = _.template(
        `<% _.forEach(sales, function(data) { %>
            <tr data-id=<%- data._id %>>
                <td><%- data.customer.email %></td>
                <td><%- data.storeLocation %></td>
                <td><%- data.items.length %></td>
                <td><%- moment.utc(data.saleDate).local().format('LLLL') %></td>
            </tr> 
        <% }); %>`);

    let rView = saleTableTemplate({'sales': data});
    $("#sale-table tbody").html(rView);

}
