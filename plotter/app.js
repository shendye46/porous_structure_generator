
const express = require('express')
const path = require('path')
const app = express()
const port = 3000
var cors = require('cors')


app.use('/static', express.static(path.join(__dirname, 'static')))

app.get('/',cors(), (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
})

app.listen(port, () => {
  console.log(`Example app listening at http://localhost:${port}`)
})

