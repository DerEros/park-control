import 'materialize-css/dist/css/materialize.min.css';
import './material-icons.css';
import 'materialize-css/dist/js/materialize.min.js'

import $ from 'jquery/dist/jquery.min.js';

import OnOff from './components/onoff.js';

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
});
