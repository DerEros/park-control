import $ from 'jquery/dist/jquery.min.js'

export default class ModeSelect {
    constructor(mode1Element, mode2Element) {
        this.mode1Element = mode1Element;
        this.mode2Element = mode2Element;

        $(mode1Element).on("click", { self: this }, this.handleMode1);
        $(mode2Element).on("click", { self: this }, this.handleMode2);
    }

    handleMode1(event) {
        console.log("Mode 1");
    }

    handleMode2(event) {
        console.log("Mode 2");
    }
}
