(async () => {
    const respuestaRaw = await fetch("./obtenerDatos1.php");
    const respuesta = await respuestaRaw.json();
    const $grafica1 = document.querySelector("#grafica1");
    const horas = respuesta.horas;
    const datosContenedorA = {
        label: "Contenedor A",
        data: respuesta.temperaturas,
        backgroundColor: 'rgba(186, 9, 88, 0.2)',
        borderWidth: 1,
    };
    
    new Chart($grafica1, {
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
