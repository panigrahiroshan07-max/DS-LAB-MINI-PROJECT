const express = require("express");

const router = express.Router();
const verifyToken = require("../middleware/authMiddleware");
const authorizeRoles = require("../middleware/roleMiddleware");
const {
  createTimetable,
  getAllTimetable,
  getTimetableByClass,
  updateTimetable,
  deleteTimetable,
} = require("../controllers/timetableController");

router.post(
  "/",
  verifyToken,
  authorizeRoles("coordinator"),
  createTimetable
);

router.get("/", getAllTimetable);

router.get("/class/:id", getTimetableByClass);


router.put(
  "/:id",
  verifyToken,
  authorizeRoles("coordinator"),
  updateTimetable
);
router.delete(
  "/:id",
  verifyToken,
  authorizeRoles("coordinator"),
  deleteTimetable
);
module.exports = router;