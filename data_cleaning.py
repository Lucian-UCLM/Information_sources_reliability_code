import json

file_path = 'code\data\politifact_factcheck_data_format.json'

with open(file_path, "r") as file:
    data = json.load(file)
    statements = data['statements']

    with open('code\data\statements_only.txt', 'w', encoding="utf-8") as outfile:
        id = 0
        for statement in statements:
            statement_text = statement['statement']
            verdict = statement['verdict']
            outfile.write(str(id) + '\t' + verdict + '\t' + statement_text + '\n')
            id += 1
            