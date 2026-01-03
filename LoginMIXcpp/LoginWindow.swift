//
//  LoginWindow.swift
//  LoginMIXcpp
//
//  Created by Bartłomiej Kuś on 03/01/2026.
//
import SwiftUI
import CppLogic

struct LoginWindow: View {
    @State private var loginInput: String = ""
    @State private var pinInput: String = ""
    @State private var message: String = ""
    
    // Obiekt bazy C++
    private var userBase: UserBase

    init() {
        // 1. Znajdujemy ścieżkę do pliku w Bundle (tak jak w ContentView)
        let path = Bundle.main.path(forResource: "users", ofType: "csv") ?? ""
        
        // 2. Wywołujemy jawny konstruktor C++, przekazując skonwertowaną ścieżkę
        // To eliminuje błąd 'init() is deprecated'
        self.userBase = UserBase(std.string(path))
    }

    var body: some View {
        VStack(spacing: 20) {
            Text("Logowanie")
                .font(.largeTitle)

            TextField("Login", text: $loginInput)
                .textFieldStyle(RoundedBorderTextFieldStyle())
                .padding(.horizontal)
            
            SecureField("PIN", text: $pinInput)
                .textFieldStyle(RoundedBorderTextFieldStyle())
                .padding(.horizontal)
            
            Button("Zaloguj") {
                checkLogin()
            }
            .buttonStyle(.borderedProminent)
            
            Text(message)
                .padding()
        }
    }
    
    func checkLogin() {
        let allUsers = userBase.getUsers()
        var success = false
        
        // Iterujemy po wektorze z C++
        for i in 0..<allUsers.size() {
            let u = allUsers[i]
            
            // Konwersja std::string na Swift String do porównania
            if String(u.getLogin()) == loginInput && String(u.getPin()) == pinInput {
                success = true
                break
            }
        }
        
        message = success ? "Zalogowano!" : "Błędne dane."
    }
}

#Preview {
    LoginWindow()
}
