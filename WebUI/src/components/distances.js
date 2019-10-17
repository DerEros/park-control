import $ from 'jquery/dist/jquery.min.js';

export default class Distances {
    constructor(form, submitBtn, initialValues) {
        this.form = form;

        this.initValues(initialValues);
        $(submitBtn).on("click", { self: this }, this.handleSubmit);
    }

    initValues(v) {
        this.form.find("#move_closer_distance").val(parseInt( v.moveCloserDistance ));
        this.form.find("#ideal_distance").val(parseInt( v.idealDistance ));
        this.form.find("#move_further_distance").val(parseInt( v.moveFurtherDistance ));
        this.form.find("#critical_distance").val(parseInt( v.criticalDistance ));
    }

    handleSubmit(event) {
        let self = event.data.self;
        let form = $(self.form);

        let values = {
            moveCloserDistance: parseInt(form.find("#move_closer_distance").val()),
            idealDistance: parseInt(form.find("#ideal_distance").val()),
            moveFurtherDistance: parseInt(form.find("#move_further_distance").val()),
            criticalDistance: parseInt(form.find("#critical_distance").val())
        }

        console.log(JSON.stringify(values));

        $.post("/parkcontrol/distances", JSON.stringify(values))
            .fail(() => { alert("Upload of distances failed!"); })
    }
}
