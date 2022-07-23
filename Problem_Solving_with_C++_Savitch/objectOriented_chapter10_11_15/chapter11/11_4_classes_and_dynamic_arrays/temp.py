class User: 
    def __init__(self,user):
        self.setUser(user)
    
    def getUser(self):   #変数(user)を表示するメソッド
        return self.__user
    
    def setUser(self, user):  #クラス内の変数(user)に値を代入するメソッド
        self.__user = user

if __name__ == "__main__":
    tanaka = User("tanaka") #User(クラス) のインスタンス生成
    tanaka.setUser("田中")  #変数(user)に"田中"を代入 

print(tanaka.getUser())  #アウトプット：田中


# [説明]
# クラスは、データや処理の定義をまとめた雛型のようなものであり、
# これらのデータやメソッドを使うためには「インスタンス」と呼ばれるものを生成する必要があります。

