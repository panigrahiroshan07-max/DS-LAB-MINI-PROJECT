import { Link } from "react-router-dom";

function Sidebar() {
  const role = localStorage.getItem("role");

  const handleLogout = () => {
    localStorage.removeItem("token");
    localStorage.removeItem("role");
    localStorage.removeItem("user_id");

    window.location.href = "/";
  };

  return (
    <div>
      {role === "teacher" && (
        <>
          <h3>Teacher Menu</h3>

          <ul>
            <li><Link to="/teacher">Dashboard</Link></li>
            <li><Link to="/teacher/students">Students</Link></li>
            <li><Link to="/teacher/lectures">Lectures</Link></li>
            <li><Link to="/teacher/attendance">Attendance</Link></li>
            <li><Link to="/teacher/requests">Correction Requests</Link></li>
            <li><Link to="/teacher/timetable">Timetable</Link></li>
            <li><Link to="/teacher/calendar">Calendar</Link></li>
          </ul>
        </>
      )}

      {role === "student" && (
        <>
          <h3>Student Menu</h3>

          <ul>
            <li><Link to="/student">Dashboard</Link></li>
            <li><Link to="/student/attendance">My Attendance</Link></li>
            <li><Link to="/student/requests">My Requests</Link></li>
          </ul>
        </>
      )}

      {role === "coordinator" && (
        <>
          <h3>Coordinator Menu</h3>

          <ul>
            <li><Link to="/coordinator">Dashboard</Link></li>
<li>
  <Link to="/coordinator/students">
    Manage Students
  </Link>
</li>
            <li>
              <Link to="/coordinator/timetable">
                Manage Timetable
              </Link>
            </li>

            <li>
              <Link to="/coordinator/calendar">
                Manage Calendar
              </Link>
            </li>

            <li>
              <Link to="/coordinator/reports">
                Reports
              </Link>
            </li>
          </ul>
        </>
      )}

      <hr />

      <button onClick={handleLogout}>
        Logout
      </button>
    </div>
  );
}

export default Sidebar;