import sys  
from PyQt5 import QtWidgets
import calculator_design
from functools import partial
import math

class ExampleApp(QtWidgets.QMainWindow, calculator_design.Ui_MainWindow):

    # Выводит введённые данные в строку команды
    def print_value(self,tag):
        global ready_flag

        if ready_flag == 0 and (tag == '+' or tag == '-' or tag == '*' or tag == '/'):
            print('Я тут!!')
            ready_flag = 1

        if ready_flag == 1:
            new_text = self.result_text.toPlainText() + tag
            self.result_text.setPlainText(new_text)
        if ready_flag == 0:
            new_text = tag
            self.result_text.setPlainText(new_text)
            ready_flag = 1

    # Вычисляет значение выражения
    def get_equally(self,tag):
            global ready_flag
            
            if(tag == '='):
                result = str(eval(self.result_text.toPlainText()))
            
            if(tag == '1/x'):
                formula = '1/(' + self.result_text.toPlainText() + ')'
                print(formula)
                result = str(eval(formula))
            
            if(tag == '%'):
                formula = self.result_text.toPlainText() + '/100'
                result = str(eval(formula))
            
            if(tag == '√'):
                formula = 'math.sqrt(' + self.result_text.toPlainText() + ')'
                print(formula)
                result = str(eval(formula))

            if(tag == '^'):
                formula  = self.result_text.toPlainText() + '**2'
                if(formula[0] == '-'):
                    formula = formula[1:len(formula)]
                print(formula)
                result = str(eval(formula))

            if(tag == 'hex'):
                formula = self.result_text.toPlainText()
                result = str(hex(eval(formula)))
                print(result)
            
            if(tag == 'bin'): # C
                formula = self.result_text.toPlainText()
                result = str(bin(eval(formula)))
                print(result)
            
            if(tag == 'CE'):
                result = ''
            
            if(tag == '+-'):
                formula = int(self.result_text.toPlainText())
                formula = formula * (-1)
                result = str(formula)

            self.result_text.setPlainText(result)
            ready_flag = 0

    # Основная функция
    def __init__(self):
        global ready_flag
        ready_flag = 1
        super().__init__()
        self.setupUi(self)   

        values = ['0','1','2','3','4','5','6','7','8','9','.','/','*','-','+','1/x', '%', '√', '^', 'hex', 'bin', 'CE', '+-', '=']

        # Number block (1, 2, 3, 4, 5, 6, 7, 8, 9, 0, ',')
        self.zero_button.clicked.connect(partial(self.print_value,values[0]))
        self.one_button.clicked.connect(partial(self.print_value,values[1]))
        self.two_button.clicked.connect(partial(self.print_value,values[2]))
        self.three_button.clicked.connect(partial(self.print_value,values[3]))
        self.four_button.clicked.connect(partial(self.print_value,values[4]))
        self.five_button.clicked.connect(partial(self.print_value,values[5]))
        self.six_button.clicked.connect(partial(self.print_value,values[6]))
        self.seven_button.clicked.connect(partial(self.print_value,values[7]))
        self.eight_button.clicked.connect(partial(self.print_value,values[8]))
        self.nine_button.clicked.connect(partial(self.print_value,values[9]))
        self.comma_button.clicked.connect(partial(self.print_value,values[10]))

        # Operations block (/, *, -, +)
        self.division_button.clicked.connect(partial(self.print_value,values[11]))
        self.multiplication_button.clicked.connect(partial(self.print_value,values[12]))
        self.minus_button.clicked.connect(partial(self.print_value,values[13]))
        self.plus_button.clicked.connect(partial(self.print_value,values[14]))
        
        # Functional block (1/x, %, √, ^, hex, C, CE, +-, =)
        self.opposite_button.clicked.connect(partial(self.get_equally,values[15]))
        self.percent_button.clicked.connect(partial(self.get_equally,values[16]))
        self.square_root_button.clicked.connect(partial(self.get_equally,values[17]))
        self.square_button.clicked.connect(partial(self.get_equally,values[18]))
        self.hex_button.clicked.connect(partial(self.get_equally,values[19]))
        self.bin_button.clicked.connect(partial(self.get_equally,values[20]))
        self.ce_button.clicked.connect(partial(self.get_equally,values[21]))
        self.plus_minus_button.clicked.connect(partial(self.get_equally,values[22]))
        self.equally_button.clicked.connect(partial(self.get_equally,values[23]))

def main():
    app = QtWidgets.QApplication(sys.argv) 
    window = ExampleApp()  
    window.show() 
    app.exec_()  

if __name__ == '__main__':  
    main() 