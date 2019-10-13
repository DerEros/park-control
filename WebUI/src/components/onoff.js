import $ from 'jquery/dist/jquery.slim.min.js';

export default class OnOff {

    constructor(element) {
        this.myProp = "foo";

        $(element).on("change", { self: this }, this.handleOnOffChange);
    }

    handleOnOffChange(event) {
        console.log(event);
        let self = event.data.self;
        alert("Switch " + self.myProp + " changed.");
    }
}
