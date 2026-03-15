def main():
    # Your code here
    pass


# __name__ is a special built-in variable that gets its value depending on how the script is executed.
# for ex: if you run the file directly from the command line, __name__ will be set to "__main__". The condition evaluates to true and the main() function will be executed.
# But if you import the file as a module in another script, __name__ will be set to the name of the file (without the .py extension).
if __name__ == "__main__":
    main()