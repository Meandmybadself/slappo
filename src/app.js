const Particle = require('particle-api-js');

const start = async () => {
    const particle = new Particle();
    let counter = 0;
    let token;

    try {
        token = await particle.login({ username: process.env.PARTICLE_USER, password: process.env.PARTICLE_PASS });
    } catch (e) {
        window.alert("Invalid Particle credentials.")
    }

    particle.getEventStream({ name: 'slap', auth: token.body.access_token }).then(function (stream) {
        stream.on('event', function (data) {
            console.log('event', data)
            counter++;
            document.getElementById('counter').innerHTML = counter;
        });
    });

}

start()