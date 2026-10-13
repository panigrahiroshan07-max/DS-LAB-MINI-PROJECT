function login(){

    localStorage.setItem(
        "role",
        "coordinator"
    );

    window.location =
    "coordinator/dashboard.html";
}