# DOKUMENTASI PROGRAM DRAFT PICK MOBILE LEGENDS
## EAS Struktur Data - Kelompok 5 Kelas C

---

# BAGIAN 1: FLOWCHART / ALGORITMA PROGRAM

## 1.1 Flowchart Utama Program

```
                    +------------------+
                    |      START       |
                    +------------------+
                            |
                            v
                    +------------------+
                    | Inisialisasi:    |
                    | - Load 125 Hero  |
                    | - Insert ke BST  |
                    | - Insert ke AVL  |
                    | - Insert ke SLL  |
                    +------------------+
                            |
                            v
                    +------------------+
                    | Tampilkan Menu   |
                    |     Utama        |
                    +------------------+
                            |
                            v
                    +------------------+
                    | Input Pilihan    |
                    +------------------+
                            |
            +---------------+---------------+
            |       |       |       |       |
            v       v       v       v       v
         [1]     [2]     [3-4]   [5]     [7]
        Draft  Manage   View   Search  Export
         Pick   Hero    Tree    Hero    Data
            |       |       |       |       |
            +-------+-------+-------+-------+
                            |
                            v
                    +------------------+
                    | Pilihan = 0 ?    |
                    +------------------+
                      |           |
                     YES          NO
                      |           |
                      v           +-----> (Kembali ke Menu)
                    +------------------+
                    |       END        |
                    +------------------+
```

## 1.2 Flowchart Draft Pick (Menu 1)

```
+------------------+
| START DRAFT PICK |
+------------------+
        |
        v
+------------------+
| Reset semua data:|
| - Clear banned   |
| - Clear picked   |
| - Reload heroes  |
+------------------+
        |
        v
+------------------+
|   BAN PHASE      |
|   (6 kali)       |
+------------------+
        |
        v
+------------------+
| i = 0            |
+------------------+
        |
        v
+------------------+
| i < 6 ?          |----NO----> [PICK PHASE]
+------------------+
        |
       YES
        |
        v
+------------------+
| Tentukan team:   |
| BLUE/RED/BLUE/   |
| RED/BLUE/RED     |
+------------------+
        |
        v
+------------------+
| Tampilkan hero   |
| yang tersedia    |
| (Single LL)      |
+------------------+
        |
        v
+------------------+
| Input nomor hero |
+------------------+
        |
        v
+------------------+
| Nomor valid?     |----NO----> (Ulangi input)
+------------------+
        |
       YES
        |
        v
+------------------+
| Insert hero ke   |
| bannedHeroes     |
| (Double LL)      |
+------------------+
        |
        v
+------------------+
| Push ke Stack    |
| (History)        |
+------------------+
        |
        v
+------------------+
| Remove dari      |
| availableHeroes  |
| (Single LL)      |
+------------------+
        |
        v
+------------------+
| i = i + 1        |
+------------------+
        |
        +-----------> (Kembali ke loop)


+------------------+
|   PICK PHASE     |
|   (10 kali)      |
+------------------+
        |
        v
+------------------+
| j = 0            |
+------------------+
        |
        v
+------------------+
| j < 10 ?         |----NO----> [HASIL AKHIR]
+------------------+
        |
       YES
        |
        v
+------------------+
| Tentukan team:   |
| Snake draft:     |
| B-R-R-B-B-R-R-   |
| B-B-R            |
+------------------+
        |
        v
+------------------+
| Tampilkan hero   |
| yang tersedia    |
+------------------+
        |
        v
+------------------+
| Input nomor hero |
+------------------+
        |
        v
+------------------+
| Nomor valid?     |----NO----> (Ulangi input)
+------------------+
        |
       YES
        |
        v
+------------------+
| Insert hero ke   |
| pickedBlue atau  |
| pickedRed (DLL)  |
+------------------+
        |
        v
+------------------+
| Push ke Stack    |
| (History)        |
+------------------+
        |
        v
+------------------+
| Remove dari      |
| availableHeroes  |
+------------------+
        |
        v
+------------------+
| j = j + 1        |
+------------------+
        |
        +-----------> (Kembali ke loop)


+------------------+
|   HASIL AKHIR    |
+------------------+
        |
        v
+------------------+
| Tampilkan:       |
| - Banned heroes  |
| - Team BLUE picks|
| - Team RED picks |
+------------------+
        |
        v
+------------------+
| Export ke file   |
| draft_result.txt |
+------------------+
        |
        v
+------------------+
|       END        |
+------------------+
```

## 1.3 Flowchart BST Insert (Rekursif)

```
+------------------+
| insertRec(node,  |
|    hero)         |
+------------------+
        |
        v
+------------------+
| node == NULL ?   |
+------------------+
        |
       YES ---------> Return new BSTNode(hero)
        |
       NO
        |
        v
+------------------+
| hero.name <      |
| node.data.name ? |
+------------------+
        |
       YES ---------> node.left = insertRec(node.left, hero)
        |
       NO
        |
        v
+------------------+
| hero.name >      |
| node.data.name ? |
+------------------+
        |
       YES ---------> node.right = insertRec(node.right, hero)
        |
       NO
        |
        v
+------------------+
| Return node      |
+------------------+
```

## 1.4 Flowchart AVL Insert dengan Balancing

```
+------------------+
| insertRec(node,  |
|    hero)         |
+------------------+
        |
        v
+------------------+
| node == NULL ?   |----YES----> Return new AVLNode(hero)
+------------------+
        |
       NO
        |
        v
+------------------+
| Insert seperti   |
| BST biasa        |
| (berdasarkan     |
|  power)          |
+------------------+
        |
        v
+------------------+
| Update height    |
| node             |
+------------------+
        |
        v
+------------------+
| Hitung balance   |
| factor           |
+------------------+
        |
        v
+------------------+
| balance > 1 ?    |
| (Left Heavy)     |
+------------------+
        |
       YES
        |
        v
+------------------+
| Left-Left atau   |
| Left-Right case? |
+------------------+
        |
    LL: rightRotate(node)
    LR: leftRotate(node.left), rightRotate(node)
        |
        v
+------------------+
| balance < -1 ?   |
| (Right Heavy)    |
+------------------+
        |
       YES
        |
        v
+------------------+
| Right-Right atau |
| Right-Left case? |
+------------------+
        |
    RR: leftRotate(node)
    RL: rightRotate(node.right), leftRotate(node)
        |
        v
+------------------+
| Return node      |
+------------------+
```

---

# BAGIAN 2: KONSEP STRUKTUR DATA YANG DIGUNAKAN

## 2.1 Abstract Data Type (ADT) - Struct Hero

```
+------------------------------------------+
|              STRUCT HERO                 |
+------------------------------------------+
| Atribut:                                 |
| - name     : string (nama hero)          |
| - role     : string (Tank/Fighter/dll)   |
| - power    : int (rating kekuatan 1-100) |
| - pickRate : int (popularitas 1-100)     |
+------------------------------------------+
| Constructor:                             |
| - Hero()                                 |
| - Hero(name, role, power, pickRate)      |
+------------------------------------------+

Contoh:
Hero("Ling", "Assassin", 93, 85)
Hero("Chou", "Fighter", 90, 92)
```

## 2.2 Single Linked List

```
Digunakan untuk: Menyimpan daftar hero yang tersedia (availableHeroes)

Struktur Node:
+--------+--------+
|  data  |  next  |
| (Hero) | (ptr)  |
+--------+--------+

Visualisasi:
HEAD -> [Tigreal|*] -> [Akai|*] -> [Franco|*] -> ... -> [Chip|NULL]

Operasi:
- insert(hero)  : O(n) - tambah di akhir
- remove(name)  : O(n) - hapus berdasarkan nama
- search(name)  : O(n) - cari berdasarkan nama
- display()     : O(n) - tampilkan semua

Penggunaan dalam program:
- Menyimpan hero yang belum di-ban/pick
- Setiap kali hero di-ban/pick, di-remove dari list
```

## 2.3 Double Linked List

```
Digunakan untuk: bannedHeroes, pickedBlue, pickedRed

Struktur Node:
+--------+--------+--------+
|  prev  |  data  |  next  |
| (ptr)  | (Hero) | (ptr)  |
+--------+--------+--------+

Visualisasi:
NULL <- [Ling] <-> [Beatrix] <-> [Chou] -> NULL
         ^                         ^
        HEAD                      TAIL

Operasi:
- insertBack(hero) : O(1) - tambah di akhir
- remove(name)     : O(n) - hapus node
- displayForward() : O(n) - tampilkan dari depan

Keunggulan dibanding SLL:
- Bisa traverse 2 arah
- Delete lebih efisien jika punya pointer ke node
```

## 2.4 Stack (LIFO - Last In First Out)

```
Digunakan untuk: Menyimpan history aksi (undo capability)

Struktur:
        +--------+
  TOP ->| PICK-R | <- Aksi terakhir
        +--------+
        | PICK-B |
        +--------+
        | BAN-R  |
        +--------+
        | BAN-B  | <- Aksi pertama
        +--------+

Operasi:
- push(action, hero) : O(1) - tambah di top
- pop()              : O(1) - ambil dari top
- peek()             : O(1) - lihat top tanpa hapus

Penggunaan:
- Setiap BAN/PICK di-push ke stack
- Bisa digunakan untuk fitur UNDO
- Menampilkan history dari yang terbaru
```

## 2.5 Queue (FIFO - First In First Out)

```
Digunakan untuk: Mengatur urutan giliran draft

Struktur:
FRONT                                    REAR
  |                                        |
  v                                        v
[BLUE-BAN] -> [RED-BAN] -> [BLUE-BAN] -> [RED-BAN] -> ...

Operasi:
- enqueue(team, phase) : O(1) - tambah di rear
- dequeue()            : O(1) - ambil dari front

Penggunaan:
- Menentukan giliran tim mana yang ban/pick
- Urutan: B-R-B-R-B-R (ban), B-R-R-B-B-R-R-B-B-R (pick)
```

## 2.6 Binary Search Tree (BST)

```
Digunakan untuk: Menyimpan hero terurut berdasarkan NAMA (A-Z)

Properti BST:
- Node kiri < Node parent
- Node kanan > Node parent

Visualisasi (sorted by name):
                    [Kagura]
                   /        \
            [Chou]          [Ling]
           /      \        /      \
       [Akai]  [Gusion] [Lancelot] [Tigreal]

Operasi (Average Case):
- insert(hero)  : O(log n)
- delete(name)  : O(log n)
- search(name)  : O(log n)
- inorder()     : O(n) - menghasilkan urutan A-Z

Traversal:
- Inorder   : Left -> Root -> Right (sorted)
- Preorder  : Root -> Left -> Right
- Postorder : Left -> Right -> Root
```

## 2.7 AVL Tree (Self-Balancing BST)

```
Digunakan untuk: Menyimpan hero terurut berdasarkan POWER

Properti AVL:
- Semua properti BST
- |height(left) - height(right)| <= 1 untuk setiap node
- Self-balancing dengan rotasi

Visualisasi (sorted by power):
                    [Kagura:89]
                   /            \
          [Chou:90]              [Ling:93]
         /         \            /         \
    [Franco:85]  [Gusion:91] [Lancelot:90] [Fanny:92]

Rotasi untuk balancing:
1. Left-Left   -> Right Rotate
2. Right-Right -> Left Rotate
3. Left-Right  -> Left Rotate + Right Rotate
4. Right-Left  -> Right Rotate + Left Rotate

Operasi (Guaranteed):
- insert : O(log n)
- delete : O(log n)
- search : O(log n)

Keunggulan dibanding BST biasa:
- Tidak bisa menjadi skewed (miring)
- Performa konsisten O(log n)
```

## 2.8 Priority Queue

```
Digunakan untuk: Rekomendasi hero berdasarkan power (prioritas)

Struktur (Sorted Linked List implementation):
HEAD -> [Ling:93] -> [Fanny:92] -> [Gusion:91] -> ... -> [Balmond:75]
         ^                                                    ^
    Highest Priority                                  Lowest Priority

Operasi:
- enqueue(hero, priority) : O(n) - insert sorted
- dequeue()               : O(1) - ambil yang tertinggi

Penggunaan:
- Memberikan rekomendasi hero terbaik
- Filter berdasarkan role
- Hero dengan power tertinggi di-recommend duluan
```

## 2.9 Sorting Algorithms

### Quick Sort
```
Digunakan untuk: Sorting array hero berdasarkan power (descending)

Algoritma:
1. Pilih pivot (elemen terakhir)
2. Partisi: elemen > pivot di kiri, < pivot di kanan
3. Rekursif sort kiri dan kanan

Visualisasi:
[80, 93, 85, 90, 75] -> pivot = 75
[80, 93, 85, 90] | 75 | []
...
[93, 90, 85, 80, 75] (sorted descending)

Kompleksitas:
- Average: O(n log n)
- Worst: O(n^2)
```

### Merge Sort
```
Digunakan untuk: Sorting array hero berdasarkan nama (A-Z)

Algoritma:
1. Divide: bagi array jadi 2
2. Conquer: sort masing-masing bagian (rekursif)
3. Combine: merge 2 array yang sudah sorted

Visualisasi:
[Ling, Chou, Akai, Gusion]
       /              \
[Ling, Chou]    [Akai, Gusion]
   /    \          /      \
[Ling] [Chou]  [Akai]  [Gusion]
   \    /          \      /
[Chou, Ling]    [Akai, Gusion]
       \              /
[Akai, Chou, Gusion, Ling]

Kompleksitas:
- Always: O(n log n)
- Space: O(n)
```

## 2.10 Rekursif

```
Fungsi rekursif yang digunakan:

1. countHeroByRoleRec(arr, n, role)
   - Base case: n <= 0, return 0
   - Recursive: count + countHeroByRoleRec(arr, n-1, role)
   
2. sumPowerRec(arr, n)
   - Base case: n <= 0, return 0
   - Recursive: arr[n-1].power + sumPowerRec(arr, n-1)

3. BST/AVL traversal (inorder, preorder, postorder)
   - Base case: node == NULL
   - Recursive: traverse left, process, traverse right

4. BST/AVL insert, delete, search
   - Base case: node == NULL atau found
   - Recursive: ke subtree kiri atau kanan
```

---

# BAGIAN 3: TABEL RINGKASAN

## 3.1 Struktur Data dan Penggunaannya

| Struktur Data | Variabel | Fungsi |
|---------------|----------|--------|
| Single Linked List | availableHeroes | Daftar hero yang bisa dipilih |
| Double Linked List | bannedHeroes | Hero yang di-ban |
| Double Linked List | pickedBlue | Hero tim BLUE |
| Double Linked List | pickedRed | Hero tim RED |
| Stack | history | Riwayat aksi BAN/PICK |
| Queue | draftOrder | Urutan giliran draft |
| BST | bstHeroes | Database hero (sorted by name) |
| AVL Tree | avlHeroes | Database hero (sorted by power) |
| Priority Queue | recommendations | Rekomendasi hero |

## 3.2 Kompleksitas Waktu

| Operasi | SLL | DLL | Stack | Queue | BST (avg) | AVL |
|---------|-----|-----|-------|-------|-----------|-----|
| Insert | O(n) | O(1) | O(1) | O(1) | O(log n) | O(log n) |
| Delete | O(n) | O(n) | O(1) | O(1) | O(log n) | O(log n) |
| Search | O(n) | O(n) | - | - | O(log n) | O(log n) |
| Access | O(n) | O(n) | O(1) | O(1) | O(log n) | O(log n) |

---

# BAGIAN 4: PSEUDOCODE FUNGSI UTAMA

## 4.1 Main Program
```
PROGRAM DraftPickML
BEGIN
    // Inisialisasi
    FOR each hero IN heroPool DO
        bstHeroes.insert(hero)
        avlHeroes.insert(hero)
        availableHeroes.insert(hero)
    END FOR
    
    // Main loop
    REPEAT
        displayMenu()
        READ choice
        
        SWITCH choice
            CASE 1: startDraftPick()
            CASE 2: manageHeroMenu()
            CASE 3: bstHeroes.displayInorder()
            CASE 4: avlHeroes.displayInorder()
            CASE 5: searchHero()
            CASE 6: heroStatistics()
            CASE 7: exportData()
            CASE 8: viewHistory()
            CASE 9: showRecommendations()
        END SWITCH
    UNTIL choice = 0
END

## 4.2 Draft Pick
```
PROCEDURE startDraftPick()
BEGIN
    // Reset
    clearAllLists()
    reloadHeroes()
    
    // BAN PHASE
    banOrder = ["BLUE", "RED", "BLUE", "RED", "BLUE", "RED"]
    FOR i = 0 TO 5 DO
        team = banOrder[i]
        displayAvailableHeroes()
        READ heroNumber
        hero = getHeroByNumber(heroNumber)
        bannedHeroes.insertBack(hero)
        history.push("BAN-" + team, hero)
        availableHeroes.remove(hero.name)
    END FOR
    
    // PICK PHASE
    pickOrder = ["BLUE","RED","RED","BLUE","BLUE","RED","RED","BLUE","BLUE","RED"]
    FOR i = 0 TO 9 DO
        team = pickOrder[i]
        displayAvailableHeroes()
        READ heroNumber
        hero = getHeroByNumber(heroNumber)
        IF team = "BLUE" THEN
            pickedBlue.insertBack(hero)
        ELSE
            pickedRed.insertBack(hero)
        END IF
        history.push("PICK-" + team, hero)
        availableHeroes.remove(hero.name)
    END FOR
    
    displayDraftResult()
    exportDraftResult()
END
```

---

2025 - EAS Struktur Data - UPN Veteran Jawa Timur
Kelompok 5 Kelas C - Galih Aji Pangestu & Fidelia Hahas Asabela
