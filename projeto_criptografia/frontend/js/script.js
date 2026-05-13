async function enviar() {
    const resposta = await fetch("http://localhost:8080");

    const texto = await resposta.text();

    document.getElementById("texto").innerHTML = texto;
}