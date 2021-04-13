libs = (("libmpich.so.12", "mpichv31"),
        #("libmpi.so.12", "mpichv3x"),
        ("libmpi.so.0", "openmpiv13"),
        ("libmpi.so.1", "openmpiv17"),
        ("libmpi.so.1", "openmpiv15"),
        ("libmpi.so.20", "openmpiv20"),
        ("libmpi.so.40", "openmpiv30"),)

if __name__ == "__main__":
    for a,b in libs:
        print(b)
