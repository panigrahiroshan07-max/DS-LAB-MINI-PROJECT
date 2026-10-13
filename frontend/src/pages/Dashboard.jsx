function Dashboard() {
  const role = localStorage.getItem("role");

  return (
    <div style={{ padding: "20px" }}>
      <h1>Smart Attendance Dashboard</h1>

      <h3>Logged in as: {role}</h3>

      <hr />

      {role === "student" && (
        <>
          <button>My Attendance</button>
          <button>Correction Requests</button>
        </>
      )}

      {role === "teacher" && (
        <>
          <button>Mark Attendance</button>
          <button>Manage Lectures</button>
          <button>View Requests</button>
        </>
      )}

      {role === "coordinator" && (
        <>
          <button>Manage Timetable</button>
          <button>Manage Calendar</button>
          <button>View Reports</button>
        </>
      )}
    </div>
  );
}

export default Dashboard;