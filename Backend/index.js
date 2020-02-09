const express = require('express')
const app = express()
const bodyParser = require('body-parser')
const cors = require('cors')
const Reading = require('./models/reading.js')




app.use(cors())
app.use(express.static('build'))
app.use(bodyParser.json())


const displayResult = function(result) {
  console.log(JSON.stringify(result, null, 2));
};
const displayError = function(err) {
  console.log(err);
};




const formatReading = (reading) => {
  return {
    
        sensor: reading.sensor,    
        gx: reading.gx,
        gy: reading.gy,
        gz: reading.gz,
        ga: reading.ga,
        gb: reading.gb
      
  }
}



// this page should never be displayed
app.get('/', (req, res) => {
  res.send('<h1>Nothing to see here.</h1>')
})




// return sensor data from cloud database
app.get('/api/reading', (req, res) => {
  
  
  Reading
  .find({})
  .then(reading => {
    

    res.json(reading.map(formatReading))

  })
  .catch(error => {
    console.log(error)
    response.status(404).send({ error: '404' })
  })
})




// save data from sensor to cloud database
app.post('/api/reading', (request, response) => {
  const body = request.body
  console.log(body)
  
  const reading = {
      sensor: body.sensor,
      gx: body.gx,
      gy: body.gy,
      gz: body.gz,
      ga: body.ga,
      gb: body.gb

  }
  console.log(reading.gx)
  Reading
    .findOneAndUpdate({sensor: 'sensor'}, reading, {new: true})
    .then(savedReading => {
      response.json(savedReading)
      console.log(savedReading)
  })

})






const PORT = process.env.PORT || 3001
const server = app.listen(PORT, () => {
    const host = server.address().address;
    console.log(`Server running on port ${PORT} and address: `+host)
})
