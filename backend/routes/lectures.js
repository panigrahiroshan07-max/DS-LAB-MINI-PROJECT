const express = require("express");
const router = express.Router();
const verifyToken = require("../middleware/authMiddleware");
const authorizeRoles = require("../middleware/roleMiddleware");

const {
  createLecture,
  getAllLectures,
  getLecturesByClass,
  getLecturesByTeacher,
  getLecturesBySubject,
  getLectureStatsBySubject,
  cancelLecture
} = require("../controllers/lectureController");

router.post(
  "/",
  verifyToken,
  authorizeRoles("teacher"),
  createLecture
);
router.get("/", getAllLectures);
router.get("/class/:id", getLecturesByClass);
router.get("/teacher/:id", getLecturesByTeacher);
router.get("/subject/:id", getLecturesBySubject);
router.get("/stats/subject/:id", getLectureStatsBySubject);
router.put("/cancel/:id", cancelLecture);
module.exports = router;