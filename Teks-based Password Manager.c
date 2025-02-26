/*
 * text-based Password Manager 🔐
 *🔹 Konsep: Simpan dan kelola password dalam file terenkripsi
 *🔹 Fitur: Tambah, lihat, hapus, dan cari password
 *🔹 Skill: File handling, string encryption (XOR atau Caesar Cipher sederhana)
 * 
 * ⚡ Skill yang Dipelajari
 * ✅ File Handling – Menyimpan dan membaca data dari file.
 * ✅ String Manipulation – Memproses input pengguna dan mengenkripsi data.
 * ✅ Basic Encryption – Melindungi password dengan metode enkripsi sederhana.
 * ✅ Struct & Array – Mengorganisir data password dalam struktur yang rapi.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256
#define KEY "my_secret_key" //ganti dengan kunci yang lebih aman

void xor_encrypt_decrypt(char *input, const char *key){
  size_t key_len = strlen(key);
  for (size_t i = 0; i < strlen(input); i++) {
    input[i] ^= key[i % key_len];
  }
}

void save_password(){
  char site[MAX_LEN], user[MAX_LEN], password[MAX_LEN];
  FILE *file = fopen("password.txt", "a");
  if(!file){
    printf("\033[1;31mError opening file!\033[0m\n");
    return;
  }

  printf("\033[1;31mEnter site: \033[0m");
  scanf("%s", site);
  printf("\033[1;31mEnter username: \033[0m");
  scanf("%s", user);
  printf("\033[1;31mEnter password: \033[0m");
  scanf("%s", password);

  xor_encrypt_decrypt(password, KEY);
  fprintf(file, "%s %s %s\n", site, user, password);
  fclose(file);
  printf("\033[1;34mPassword saves successfully!\033[0m\n");
}

void view_password(){
  char site[MAX_LEN], user[MAX_LEN], password[MAX_LEN];
  FILE *file = fopen("password.txt", "r");
  if(!file){
    printf("\033[1;31mNo saved password found!\033[0m\n");
    return;
  }

  printf("\n\033[1;33mStored Passwords:\033[0m\n");
  while (fscanf(file, "%s %s %s", site, user, password) != EOF) {
    xor_encrypt_decrypt(password, KEY);
    printf("\033[1;36mSite: %s | Username: %s | Password: %s\033[0m\n", site, user, password);
  }
  fclose(file);
}

int main(){
  int choice;
  do{
    printf("\n\033[1;32mText-Based Password Manager\033[0m\n");
    printf("1. Save Password\n");
    printf("2. View Password\n");
    printf("3. Exit\n");
    printf("Choose an option: \n");
    scanf("%d", &choice);

    switch (choice) {
      case 1: save_password(); break;
      case 2: view_password(); break;
      case 3: printf("\033[1;35mGoodbye!\033[0m\n"); break;
      default: printf("\033[1;35mInvalid choice\033[0m\n");
    }
  } while (choice != 3);
  return 0;
}

