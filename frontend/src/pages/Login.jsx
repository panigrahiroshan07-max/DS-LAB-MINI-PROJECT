import { useState } from "react";
import axios from "../api/axios";
import { useNavigate } from "react-router-dom";

function Login() {
  const [role, setRole] = useState("");
  const [username, setUsername] = useState("");
  const [password, setPassword] = useState("");

  const navigate = useNavigate();

  const login = async () => {
    try {
      const res = await axios.post("/auth/login", {
        username,
        password,
      });

      if (role !== res.data.role) {
        alert("Selected role does not match account");
        return;
      }

     localStorage.setItem("token", res.data.token);
localStorage.setItem("role", res.data.role);
localStorage.setItem("user_id", res.data.user_id);

      if (res.data.role === "teacher") {
        navigate("/teacher");
      }

      if (res.data.role === "student") {
        navigate("/student");
      }

      if (res.data.role === "coordinator") {
        navigate("/coordinator");
      }
    } catch (err) {
      alert("Invalid Credentials");
    }
  };

  return (
    <div style={{ padding: "50px" }}>
      <h1>Smart Attendance Tracker</h1>

      <select
        value={role}
        onChange={(e) => setRole(e.target.value)}
      >
        <option value="">Select Role</option>
        <option value="student">Student</option>
        <option value="teacher">Teacher</option>
        <option value="coordinator">Coordinator</option>
      </select>

      <br /><br />

      <input
        placeholder="Username"
        onChange={(e) => setUsername(e.target.value)}
      />

      <br /><br />

      <input
        type="password"
        placeholder="Password"
        onChange={(e) => setPassword(e.target.value)}
      />

      <br /><br />

      <button onClick={login}>Login</button>
    </div>
  );
}

export default Login;