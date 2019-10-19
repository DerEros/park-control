import 'materialize-css/dist/css/materialize.min.css';
import './material-icons.css';
import 'materialize-css/dist/js/materialize.min.js'

import $ from 'jquery/dist/jquery.min.js';

import OnOff from './components/onoff.js';
import Distances from './components/distances.js';
import ModeSelect from './components/modeselect.js';

function createDocument() {
    return $("<div></div>").html(require('./main-page.html'));
}

function initOnOff() {
    $.get("/parkcontrol/state", (result) => {
        var parkControlEnabled = true;
        if (typeof result !== "undefined") {
           parkControlEnabled = result.enabled; 
        }
        var onOff = new OnOff($("#park-control-on-off"), parkControlEnabled);
    });
}

function initDistance() {
    $.get("/parkcontrol/distances", (result) => {
        var distances = {};
        if (typeof result !== "undefined") {
            distances = result;
        }
        var distanceForm = new Distances($("#distances_form"), $("#submit_distances"), distances);
    }).fail(() => {
        var distances = {
            moveCloserDistance: 0,
            idealDistance: 0,
            moveFurtherDistance: 0,
            criticalDistance: 0
        };
        var distanceForm = new Distances($("#distances_form"), $("#submit_distances"), distances);
    });
}

function initAnimationMode() {
    var parkControlModeAction = $("#park_control_mode");
    var halloweenModeAction = $("#halloween_mode");

    var modeSelect = new ModeSelect(parkControlModeAction, halloweenModeAction);
}

$( () => {
    $("body").append(createDocument());

    initOnOff();
    initDistance();
    initAnimationMode();
});
