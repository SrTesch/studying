import express from 'express';
import dotenv from 'dotenv';
import type { Application, Request, Response } from 'express';
import usersRouter from './routes/usersRoutes.js';
dotenv.config();

const app: Application = express();
const port = Number(process.env.PORT) || 3000;

app.get('/', (_req: Request, res: Response)=>{
    res.send('Eusoulindo');
})

app.use('/users', usersRouter);


app.listen(port, ()=>{
    console.log("Servidor rodando na porta: ", port);
})