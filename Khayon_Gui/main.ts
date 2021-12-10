const { app, BrowserWindow } = require('electron')
const path = require('path')

let win;


try{
    require('electron-reloader')(module)
}catch(_){}


function createWindow () {
  const win = new BrowserWindow({
    /*toolbar: false,*/
    width: 800,
    height: 600,
    webPreferences: {
    preload: path.join(__dirname, 'preload.js')
    }
  })
  /*win.setMenu(null)*/
  win.loadFile('index.html')
}

app.whenReady().then(() => {
  createWindow()

  app.on('activate', () => {
    if (BrowserWindow.getAllWindows().length === 0) {
      createWindow()
    }
  })
})

app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit()
  }
})



