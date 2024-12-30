# Login-Registration-System
This is my Login &amp; Registration system project in C++
You can create accounts, and login to the ones that are already created.

_______________________
Features:
- Account Creation & Deletion: Users can create and delete accounts associated with their email addresses. Account creation requires the user to provide a password, which is securely stored after being hashed. Account deletion is restricted to the owner of the account.
- Password Protection: Passwords are stored in a pseudo-database, represented by a "database2.csv" file. Each password is hashed using the SHA-256 algorithm from the OpenSSL library, ensuring a 256-bit (32-byte) hash. The hash is then converted into a hexadecimal string, with each byte represented as two hexadecimal characters (using the set "0123456789abcdef") for secure and consistent storage.
- Email Validation: Upon account creation or modification, the user’s provided email address is verified for correctness. This validation checks whether the domain of the entered email exists by cross-referencing it against a list of known, valid email domains stored in a file (e.g., "domains.txt"). This file contains approximately 100 common email domains, ensuring the entered address is consistent with common domain formats.
- Login Attempt Limitation: A three-strike login mechanism is implemented. Users are allowed up to three attempts to input their correct password. If all attempts fail, the program automatically returns to the home screen, ensuring protection against brute-force attacks.

_______________________
Future plans:
- Enhanced Account Creation 
- Overhauled Three-Strike Security System
- SQL Database Integration
