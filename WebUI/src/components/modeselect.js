import $ from 'jquery/dist/jquery.min.js'

export default class ModeSelect {
    constructor(mode1Element, mode2Element) {
        this.mode1Element = mode1Element;
        this.mode2Element = mode2Element;

        $(mode1Element).on("click", { self: this }, this.handleMode1);
        $(mode2Element).on("click", { self: this }, this.handleMode2);
    }

    handleMode1(event) {
        event.data.self.setAnimationMode(0);
    }

    handleMode2(event) {
        event.data.self.setAnimationMode(1);
    }

    setAnimationMode(mode) {
        $.post("/parkcontrol/animationmode", JSON.stringify({"animationMode":mode}))
            .fail(() => { alert("Upload of animation mode failed!"); });
    }
}
