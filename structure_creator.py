import fire
from src.box import Box


def main(dimension=10, radius=2):
    b = Box(dimension,dimension,dimension)
    b.fillatoms(radius)
    header_atoms = r"""ITEM: TIMESTEP
1
ITEM: NUMBER OF ATOMS
{}
ITEM: BOX BOUNDS pp pp pp
{} {}
{} {}
{} {}
ITEM: ATOMS id type x y z""".format(len(b.atomlist),dimension//2,dimension//2,dimension//2,dimension//2,dimension//2,dimension//2)
    
    print(header_atoms)
    
    for atom in b.atomlist:
        print(atom)
    print("----------------pores-----------------------\n")
    header_pores = r"""ITEM: TIMESTEP
1
ITEM: NUMBER OF ATOMS
{}
ITEM: BOX BOUNDS pp pp pp
{} {}
{} {}
{} {}
ITEM: ATOMS id type x y z""".format(len(b.porelist),dimension//2,dimension//2,dimension//2,dimension//2,dimension//2,dimension//2)
    
    b.fillPores()
    print(header_pores)
    for pore in b.porelist:
        print(pore)
if __name__=="__main__":
    fire.Fire(main)