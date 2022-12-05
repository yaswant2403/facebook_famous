# CS225 Final Project (Y'ALL)
## Contributors:  
Yash Ejjagiri (yse2) \
Afif Shomali (shomali2) \
Lisa Jing Leung (ljleung2) \
Libby Codamon (ecoda2) 

## Repo Structure
Team Contract, Proposal & Weekly Logs can be found in [`documents/`](https://github.com/yaswant2403/cs225final_project/tree/main/documents)  
The dataset & testing data is stored as text files are stored in `data/`  
The tests are stored in `tests/`  
All source code files are stored in `src/`  
The entry point source files are stored in `entry/`

## Running code 

In the CS225 docker enviorment, in the root directory run:  
```
mkdir build 
cd build
```
To create a build directory, then run: 
```
cmake ..  
```
To initialize cmake, after this you can run: 
```
make main
./main 
```
(Todo: Replace the "make main" above with our actual entry and exectuable later)
