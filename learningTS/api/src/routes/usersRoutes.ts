import { Router } from "express";
import usersController from "../controllers/usersControllers.js";
const router = Router();

router.get('/', usersController.getAllUsers);

export default router;