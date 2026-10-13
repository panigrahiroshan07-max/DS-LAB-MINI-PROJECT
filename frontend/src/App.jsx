import { BrowserRouter, Routes, Route } from "react-router-dom";

import Login from "./pages/Login";
import TeacherDashboard from "./pages/teacher/TeacherDashboard";
import Students from "./pages/teacher/Students";
import Lectures from "./pages/teacher/Lectures";
import Attendance from "./pages/teacher/Attendance";
import CorrectionRequests from "./pages/teacher/CorrectionRequests";
import Timetable from "./pages/teacher/Timetable";
import Calendar from "./pages/teacher/Calendar";
import StudentDashboard from "./pages/student/StudentDashboard";
import MyAttendance from "./pages/student/MyAttendance";
import MyRequests from "./pages/student/MyRequests";
import CoordinatorDashboard from "./pages/coordinator/CoordinatorDashboard";
import ManageTimetable from "./pages/coordinator/ManageTimetable";
import ManageCalendar from "./pages/coordinator/ManageCalendar";
import Reports from "./pages/coordinator/Reports";
import ProtectedRoute from "./components/ProtectedRoute";
import LinkedListDemo from "./pages/LinkedListDemo";
import ManageStudents from "./pages/coordinator/ManageStudents";

function App() {
  return (
    <BrowserRouter>
     <Routes>
  <Route path="/" element={<Login />} />

  {/* Teacher Routes */}
  <Route
    path="/teacher"
    element={
      <ProtectedRoute allowedRole="teacher">
        <TeacherDashboard />
      </ProtectedRoute>
    }
  />

  <Route
    path="/teacher/students"
    element={
      <ProtectedRoute allowedRole="teacher">
        <Students />
      </ProtectedRoute>
    }
  />

  <Route
    path="/teacher/lectures"
    element={
      <ProtectedRoute allowedRole="teacher">
        <Lectures />
      </ProtectedRoute>
    }
  />

  <Route
    path="/teacher/attendance"
    element={
      <ProtectedRoute allowedRole="teacher">
        <Attendance />
      </ProtectedRoute>
    }
  />

  <Route
    path="/teacher/requests"
    element={
      <ProtectedRoute allowedRole="teacher">
        <CorrectionRequests />
      </ProtectedRoute>
    }
  />

  <Route
    path="/teacher/timetable"
    element={
      <ProtectedRoute allowedRole="teacher">
        <Timetable />
      </ProtectedRoute>
    }
  />

  <Route
    path="/teacher/calendar"
    element={
      <ProtectedRoute allowedRole="teacher">
        <Calendar />
      </ProtectedRoute>
    }
  />

  {/* Student Routes */}
  <Route
    path="/student"
    element={
      <ProtectedRoute allowedRole="student">
        <StudentDashboard />
      </ProtectedRoute>
    }
  />

  <Route
    path="/student/attendance"
    element={
      <ProtectedRoute allowedRole="student">
        <MyAttendance />
      </ProtectedRoute>
    }
  />

  <Route
    path="/student/requests"
    element={
      <ProtectedRoute allowedRole="student">
        <MyRequests />
      </ProtectedRoute>
    }
  />

  {/* Coordinator Routes */}
  <Route
    path="/coordinator"
    element={
      <ProtectedRoute allowedRole="coordinator">
        <CoordinatorDashboard />
      </ProtectedRoute>
    }
  />

  <Route
    path="/coordinator/timetable"
    element={
      <ProtectedRoute allowedRole="coordinator">
        <ManageTimetable />
      </ProtectedRoute>
    }
  />

  <Route
    path="/coordinator/calendar"
    element={
      <ProtectedRoute allowedRole="coordinator">
        <ManageCalendar />
      </ProtectedRoute>
    }
  />

  <Route
    path="/coordinator/reports"
    element={
      <ProtectedRoute allowedRole="coordinator">
        <Reports />
      </ProtectedRoute>
    }
  />

  <Route
  path="/linkedlist-demo"
  element={<LinkedListDemo />}
/>
<Route
  path="/coordinator/students"
  element={<ManageStudents />}
/>
</Routes>
    </BrowserRouter>
  );
}

export default App;