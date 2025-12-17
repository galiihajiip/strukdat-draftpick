# 🎮 Mobile Legends Draft Pick System
## EAS Struktur Data

### 📋 Deskripsi Project
Sistem simulasi Draft Pick Mobile Legends yang mengimplementasikan berbagai konsep struktur data yang dipelajari selama 1 semester.

### 👥 Kelompok
- [Nama Anggota 1]
- [Nama Anggota 2]
- [Nama Anggota 3]

---

## 📚 Implementasi Struktur Data

| No | Materi | Implementasi |
|----|--------|--------------|
| 1 | Abstract Data Type (ADT) | Struct `Hero` dengan atribut name, role, power, pickRate |
| 2 | Rekursif | `countHeroByRoleRec()`, `sumPowerRec()`, `printHeroRec()` |
| 3 | Single Linked List | Class `SingleLinkedList` untuk menyimpan available heroes |
| 4 | Double Linked List | Class `DoubleLinkedList` untuk banned & picked heroes |
| 5 | Stack | Class `Stack` untuk menyimpan history actions (undo) |
| 6 | Queue | Class `Queue` untuk mengatur urutan draft pick |
| 7 | Sorting | `quickSort()` dan `mergeSort()` untuk sorting heroes |
| 8 | Binary Search Tree (BST) | Class `BST` untuk menyimpan heroes (sorted by name) |
| 9 | AVL Tree | Class `AVLTree` untuk menyimpan heroes (sorted by power, balanced) |
| 10 | Priority Queue | Class `PriorityQueue` untuk hero recommendations |

---

## ✅ Fitur Utama (Sesuai Requirement EAS)

### Operasi BST & AVL Tree:
- ✅ **Insert** - Menambah hero baru ke database
- ✅ **Delete** - Menghapus hero dari database
- ✅ **Search** - Mencari hero berdasarkan nama
- ✅ **View** - Menampilkan semua hero (Inorder, Preorder, Postorder)
- ✅ **Export to .txt** - Export data ke file notepad

### Fitur Draft Pick:
- 🎯 **Ban Phase**: 3 ban per team (total 6 ban)
- 🎯 **Pick Phase**: 5 pick per team (total 10 pick)
- 🎯 **Snake Draft Order**: B-R-R-B-B-R-R-B-B-R
- 🎯 **125+ Hero Mobile Legends** (data real)
- 🎯 **Hero Recommendations** berdasarkan power rating

---

## 🚀 Cara Menjalankan Program

### Prasyarat
- Compiler C++ (g++, MinGW, atau Visual Studio)
- Terminal/Command Prompt

### Langkah-langkah:

#### Windows (Command Prompt/PowerShell):
```bash
# Compile
g++ -o draftpick main.cpp

# Run
./draftpick
```

#### Windows (Visual Studio):
1. Buka Visual Studio
2. Create New Project > Console App
3. Copy paste kode dari `main.cpp`
4. Build & Run (Ctrl+F5)

#### Online Compiler:
1. Buka [OnlineGDB](https://www.onlinegdb.com/online_c++_compiler)
2. Copy paste kode dari `main.cpp`
3. Klik "Run"

---

## 📖 Panduan Penggunaan

### Menu Utama:
```
╔══════════════════════════════════════════════════════════════╗
║       MOBILE LEGENDS - DRAFT PICK SYSTEM                     ║
╠══════════════════════════════════════════════════════════════╣
║  1. Start Draft Pick                                         ║
║  2. Manage Hero Database                                     ║
║  3. View All Heroes (BST - Sorted by Name)                   ║
║  4. View All Heroes (AVL - Sorted by Power)                  ║
║  5. Search Hero                                              ║
║  6. Hero Statistics                                          ║
║  7. Export Data to File                                      ║
║  8. View History (Stack)                                     ║
║  9. Hero Recommendations (Priority Queue)                    ║
║  0. Exit                                                     ║
╚══════════════════════════════════════════════════════════════╝
```

### 1. Start Draft Pick
- Memulai simulasi draft pick
- Ban 3 hero per team
- Pick 5 hero per team
- Hasil otomatis di-export ke `draft_result.txt`

### 2. Manage Hero Database
- Insert: Tambah hero baru
- Delete: Hapus hero
- View: Lihat semua hero di BST/AVL

### 3-4. View Heroes
- BST: Sorted alphabetically (A-Z)
- AVL: Sorted by power rating

### 5. Search Hero
- Cari hero berdasarkan nama
- Menampilkan detail hero (name, role, power, pick rate)

### 6. Hero Statistics
- Total heroes
- Count per role (menggunakan rekursif)
- Total power (menggunakan rekursif)

### 7. Export Data
- Export BST ke `bst_heroes.txt`
- Export AVL ke `avl_heroes.txt`
- Export draft result ke `draft_result.txt`

### 8. View History
- Menampilkan history actions (Stack)
- INSERT, DELETE, BAN, PICK

### 9. Hero Recommendations
- Rekomendasi hero berdasarkan power
- Filter by role (Tank, Fighter, Assassin, Mage, Marksman, Support)

---

## 📁 Struktur File

```
strukdat-draftpick/
├── main.cpp              # Source code utama
├── README.md             # Dokumentasi
├── bst_heroes.txt        # Export BST (generated)
├── avl_heroes.txt        # Export AVL (generated)
└── draft_result.txt      # Hasil draft pick (generated)
```

---

## 🎮 Data Hero Mobile Legends

Program ini menggunakan **125+ hero Mobile Legends** dengan data real:

| Role | Jumlah | Contoh Hero |
|------|--------|-------------|
| Tank | 20 | Tigreal, Khufra, Atlas, Johnson |
| Fighter | 34 | Chou, Paquito, Yu Zhong, Yin |
| Assassin | 16 | Ling, Gusion, Lancelot, Fanny |
| Mage | 24 | Xavier, Kagura, Valentina, Lunox |
| Marksman | 20 | Beatrix, Brody, Wanwan, Claude |
| Support | 11 | Mathilda, Angela, Estes, Rafaela |

---

## 📊 Kompleksitas Algoritma

| Struktur Data | Insert | Delete | Search |
|---------------|--------|--------|--------|
| Single Linked List | O(n) | O(n) | O(n) |
| Double Linked List | O(1)/O(n) | O(n) | O(n) |
| Stack | O(1) | O(1) | - |
| Queue | O(1) | O(1) | - |
| BST (avg) | O(log n) | O(log n) | O(log n) |
| BST (worst) | O(n) | O(n) | O(n) |
| AVL Tree | O(log n) | O(log n) | O(log n) |
| Priority Queue | O(n) | O(1) | - |

---

## 📝 Contoh Output

### Draft Result (draft_result.txt):
```
========================================
    MOBILE LEGENDS DRAFT PICK RESULT    
========================================

=== BANNED HEROES ===
- Ling (Assassin)
- Beatrix (Marksman)
- Chou (Fighter)
- Gusion (Assassin)
- Xavier (Mage)
- Khufra (Tank)

=== TEAM BLUE PICKS ===
- Lancelot (Assassin)
- Paquito (Fighter)
- Mathilda (Support)
- Kagura (Mage)
- Atlas (Tank)

=== TEAM RED PICKS ===
- Wanwan (Marksman)
- Yu Zhong (Fighter)
- Valentina (Mage)
- Franco (Tank)
- Angela (Support)
```

---

## 🔧 Troubleshooting

### Error: 'g++' is not recognized
- Install MinGW atau gunakan Visual Studio
- Atau gunakan online compiler

### Program tidak bisa compile
- Pastikan menggunakan C++11 atau lebih baru
- Compile dengan: `g++ -std=c++11 -o draftpick main.cpp`

---

## 📚 Referensi
- Mobile Legends: Bang Bang Official
- Materi Kuliah Struktur Data
- Data Structures and Algorithms in C++ - Adam Drozdek

---

## 📄 License
Project ini dibuat untuk keperluan akademik (EAS Struktur Data).

---

**© 2024 - EAS Struktur Data**
