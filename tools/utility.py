from SCons.Node.FS import Dir, File, Entry

# this is from https://github.com/nanobyte-dev/nanobyte_os/blob/master/build_scripts/utility.py#L44

def FindIndex(the_list, predicate):
    for i in range(len(the_list)):
        if predicate(the_list[i]):
            return i
    return None


def IsFileName(obj, name):
    if isinstance(obj, str):
        return name in obj
    elif isinstance(obj, File) or isinstance(obj, Dir) or isinstance(obj, Entry):
        return obj.name == name
    return False
