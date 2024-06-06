import json

file_path = 'data\politifact_factcheck_data_format.json'

with open(file_path, "r") as file:
    data = json.load(file)
    statements = data['statements']

    with open('data\statements_only.txt', 'w', encoding="utf-8") as outfile:
        id = 0
        for statement in statements:
            statement_text = statement['statement'].replace('\n', ' ')
            verdict = statement['verdict']
            outfile.write(str(id) + ' ' + verdict + ' ' + statement_text + '\n')
            id += 1
            