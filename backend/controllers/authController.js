const db = require("../config/db");
const jwt = require("jsonwebtoken");

const login = (req, res) => {
  const { username, password } = req.body;

  const sql =
    "SELECT * FROM users WHERE username = ? AND password = ?";

  db.query(sql, [username, password], (err, result) => {
    if (err) return res.status(500).json(err);

    if (result.length === 0) {
      return res.status(401).json({
        message: "Invalid Credentials",
      });
    }

    const user = result[0];

    const token = jwt.sign(
      {
        user_id: user.user_id,
        role: user.role,
      },
      "attendance_secret_key",
      { expiresIn: "1d" }
    );

    res.json({
  message: "Login Successful",
  token,
  role: user.role,
  user_id: user.user_id,
});
  });
};

module.exports = {
  login,
};