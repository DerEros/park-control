import $ from 'jquery/dist/jquery.min.js';

export default class Distances {
    constructor(form, submitBtn, initialValues) {
        this.form = form;

        this.initValues(initialValues);
        $(submitBtn).on("click", { self: this }, this.handleSubmit);
    }

    initValues(v) {
        this.form.find("#move_closer_distance").val(v.moveCloserDistance);
        this.form.find("#ideal_distance").val(v.idealDistance);
        this.form.find("#move_further_distance").val(v.moveFurtherDistance);
        this.form.find("#critical_distance").val(v.criticalDistance);
    }

    handleSubmit(event) {
        let self = event.data.self;
        let form = $(self.form);

        let values = {
            moveCloserDistance: form.find("#move_closer_distance").val(),
            idealDistance: form.find("#ideal_distance").val(),
            moveFurtherDistance: form.find("#move_further_distance").val(),
            criticalDistance: form.find("#critical_distance").val()
        }

        $.post("/parkcontrol/distances")
            .fail(() => { alert("Upload of distances failed!"); })
    }
}
