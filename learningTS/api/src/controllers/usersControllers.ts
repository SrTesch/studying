import type { Request, Response } from "express";

const usersController = {
    getAllUsers: async (_req: Request, res: Response)=>{
        console.log("eusoulindo");
        res.send("funcionou meu bom");
    }
}

export default usersController;