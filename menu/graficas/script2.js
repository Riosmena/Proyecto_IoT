(async () => {
    const respuestaRaw = await fetch("./obtenerDatos2.php");
    const respuesta = await respuestaRaw.json();
    const $grafica2 = document.querySelector("#grafica2");
    const horas = respuesta.horas;
    const datosContenedorA = {
        label: "Contenedor A",
        data: respuesta.humedades,
        backgroundColor: 'rgba(189, 6, 240, 0.2)',
        borderWidth: 1,
    };
    
    new Chart($grafica2, {
        type: 'line',
        data: {
            labels: horas,
            datasets: [
                datosContenedorA,
            ]
        },
        options: {
            scales: {
                yAxes: [{
                    ticks: {
                        beginAtZero: true
                    }
                }],
            },
        }
    });
})();