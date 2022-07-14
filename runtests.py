#!/usr/bin/env python3

"""
This script is a simple test harness for running Proton unit tests.
"""

import os
import subprocess
import sys

def main():

    # First, check to see that the `build/tests` folder exists.
    if not os.path.isdir("build/tests"):
        print("build/tests directory does not exist.", file=sys.stderr)
        return 1
    
    # Get the list of unit tests:
    testfiles = os.listdir("build/tests")

    # Run the tests in alphabetical order:
    testfiles.sort()

    testsrun = 0
    testspassed = 0
    testsfailed = 0
    testsskipped = 0
    report = ""

    print("")
    for testfile in testfiles:
        print("- Running test {}...".format(testfile))
        testsrun += 1
        result = subprocess.Popen(
            ("build/tests/{}".format(testfile), ">", "/dev/null"))
        termout = result.communicate()[0]
        if termout is not None:
            print(termout)
        ret = result.returncode
        if ret == 0:
            report += "[PASSED]     {}\n".format(testfile)
            testspassed += 1
        elif ret == 100:
            report += "[SKIPPED]    {}\n".format(testfile)
            testsskipped += 1
        else:
            report += "[FAILED]     {}\n".format(testfile)
            testsfailed += 1
    
    print("\nAll tests have finished running!\n")
    print("Individual Test Results:")
    print("========================")
    print(report)
    print("Summary:")
    print("========")
    print("Tests Run:       {}".format(testsrun))
    print("Tests Passed:    {}".format(testspassed))
    print("Tests Skipped:   {}".format(testsskipped))
    print("Tests Failed:    {}".format(testsfailed))
    print("")

    if testsfailed == 0:
        return 0
    else:
        return 1

if __name__ == "__main__":
    sys.exit(main())