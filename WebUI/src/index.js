import 'materialize-css/dist/css/materialize.min.css';
import './material-icons.css';
import 'materialize-css/dist/js/materialize.min.js'

import $ from 'jquery/dist/jquery.min.js';

import OnOff from './components/onoff.js';
import Distances from './components/distances.js';

function createDocument() {
    return $("<div></div>").html(require('./main-page.html'));
}

$( () => {
    $("body").append(createDocument());
    var elems = document.querySelectorAll('.collapsible');
    var instances = M.Collapsible.init(elems, {});

    $.get("/parkcontrol/state", (result) => {
        var parkControlEnabled = true;
        if (typeof result !== "undefined") {
           parkControlEnabled = result.enabled; 
        }
        var onOff = new OnOff($("#park-control-on-off"), parkControlEnabled);
    });

    $.get("/parkcontrol/distances", (result) => {
        var distances = {};
        if (typeof result !== "undefined") {
            distances = result;
        }
        var distanceForm = new Distances($("#distances_form"), $("#submit_distances"), distances);
    }).fail(() => {
        var distances = {
            moveCloserDistance: parseInt(form.find("#move_closer_distance").val()),
            idealDistance: parseInt(form.find("#ideal_distance").val()),
            moveFurtherDistance: parseInt(form.find("#move_further_distance").val()),
            criticalDistance: parseInt(form.find("#critical_distance").val())
        };
        var distanceForm = new Distances($("#distances_form"), $("#submit_distances"), distances);
    });
});
