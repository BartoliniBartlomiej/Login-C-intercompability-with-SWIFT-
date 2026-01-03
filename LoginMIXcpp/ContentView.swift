import SwiftUI
import CppLogic // To jest nazwa modułu z Twojego pliku module.modulemap
import Combine

struct ContentView: View {
    @State private var outputText: String = "Kliknij, aby sprawdzić bazę"

    var body: some View {
        VStack(spacing: 20) {
            Text(outputText)
                .padding()

            Button("Dodaj i Wypisz Usera") {
                runCppLogic()
            }
        }
    }

    func getDatabasePath() -> String {
        // Pobiera ścieżkę do folderu Documents bieżącej aplikacji
        let paths = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask)
        let documentsDirectory = paths[0]
        let finalPath = documentsDirectory.appendingPathComponent("users.csv").path
        
        return finalPath
    }
    
    func runCppLogic() {
        // 1. Znajdź ścieżkę do pliku w Bundle aplikacji
        // Na zrzucie plik nazywa się "users", upewnij się czy ma rozszerzenie .csv
        guard let path = Bundle.main.path(forResource: "users", ofType: "csv") else {
            self.outputText = "Błąd: Nie znaleziono pliku users.csv w projekcie!"
            return
        }
        
        // 2. Utwórz bazę, przekazując ścieżkę (konwersja na std.string)
        var userBase = UserBase(std.string(path))
        
        // 3. Pobierz dane
        let usersVector = userBase.getUsers()
        
        if usersVector.empty() {
            self.outputText = "Baza jest pusta (plik nie został wczytany)."
            return
        }
        
        var result = ""
        for i in 0..<usersVector.size() {
            let user = usersVector[i]
            result += "ID: \(user.getId()) | Login: \(user.getLogin())\n"
        }
        self.outputText = result
    }
}
#Preview{
    ContentView()
}
