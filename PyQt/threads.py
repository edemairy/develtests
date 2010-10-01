import sys
import threading
from PyQt4 import QtGui

def affiche():
  while 1:
    print '.'

app = QtGui.QApplication(sys.argv)

widget = QtGui.QWidget()
widget.resize(250, 150)
widget.setWindowTitle('simple')
widget.show()

a = threading.Thread( None, affiche, None, (), {} )
a.start()

sys.exit(app.exec_())
