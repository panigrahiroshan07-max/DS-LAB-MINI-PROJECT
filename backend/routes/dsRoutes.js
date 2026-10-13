const express = require("express");
const router = express.Router();

const { execFile } = require("child_process");
const fs = require("fs");

const db = require("../config/db");

router.get("/students-linkedlist", (req, res) => {

  const sql = `
    SELECT
      student_id,
      roll_no,
      name
    FROM students
  `;

  db.query(sql, (err, students) => {

    if (err) {
      return res.status(500).json(err);
    }

    let fileContent = "";

    students.forEach((student) => {
      fileContent +=
        `${student.student_id}|` +
        `${student.roll_no}|` +
        `${student.name}|` +
        `75.00\n`;
    });

    fs.writeFileSync(
      "C:\\Users\\Roshan\\OneDrive\\ROSHAN_CLG\\DS LAB\\mini project\\DS_Module\\students.txt",
      fileContent
    );
console.log("students.txt created");
console.log(fileContent);
    execFile(
      "C:\\Users\\Roshan\\OneDrive\\ROSHAN_CLG\\DS LAB\\mini project\\DS_Module\\01_student_linked_list.exe",
      {
        cwd: "C:\\Users\\Roshan\\OneDrive\\ROSHAN_CLG\\DS LAB\\mini project\\DS_Module"
      },
      (error, stdout, stderr) => {

        if (error) {
          console.log("STDERR:", stderr);
          console.log("STDOUT:", stdout);

          return res.status(500).json({
            error: error.message,
            stderr,
            stdout
          });
        }

        res.json({
          output: stdout
        });

      }
    );

  });

});

module.exports = router;