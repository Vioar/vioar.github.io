function scrabblex(event) {
    event.preventDefault(); // Zabrání přesměrování formuláře

    let inputText = document.querySelector('input[name="slovo"]').value.trim(); // Získání textu
    let resultTable = document.getElementById("Table"); // Tabulka výsledků
    let resultText = document.getElementById("text"); // Buňka s výsledkem

    if (inputText) {
        resultText.innerText = inputText; // Zobrazení textu ve výsledku
        resultTable.style.display = "table"; // Zobrazení tabulky
    } else {
        resultTable.style.display = "none"; // Skrytí tabulky, pokud je pole prázdné
    }
}
