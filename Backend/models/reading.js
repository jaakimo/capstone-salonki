const mongoose = require('mongoose')


if ( process.env.NODE_ENV !== 'production' ) {
    require('dotenv').config()
  }


  // Do not push Password to Github !!!!!!!!
const url = 'mongodb+srv://capstonesalonki:XXX@cluster0-0uoxl.mongodb.net/salonki'




mongoose.connect(url, {useNewUrlParser: true})





const readingSchema = new mongoose.Schema({
  sensor: String,    
  gx: String,
  gy: String,
  gz: String
  })

  
const Reading = mongoose.model('sensors', readingSchema);
  


module.exports = Reading
