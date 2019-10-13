import $ from 'jquery/dist/jquery.min.js';

export default class OnOff {

    constructor(element) {
        this.element = element;

        $(element).on("change", { self: this }, this.handleOnOffChange);
    }

    handleOnOffChange(event) {
        let self = event.data.self;
        let checked = event.target.checked;

        if (checked) {
            $.get("/parkcontrol/on");
        } else {
            $.get("/parkcontrol/off");
        }
    }
}
