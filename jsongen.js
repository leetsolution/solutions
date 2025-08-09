const fs = require('fs');
const path = require('path');

const problemsDir = path.join(__dirname, 'problems');
const outputFile = path.join(__dirname, 'all_problems.json');
const solutionFiles = {
    python3: 'solution.py',
    java: 'solution.java',
    cpp: 'solution.cpp',
    c: 'solution.c'
};

function getProblemFolders(dir) {
    return fs.readdirSync(dir).filter(f => fs.statSync(path.join(dir, f)).isDirectory());
}

function readFileSafe(filePath) {
    try {
        return fs.readFileSync(filePath, 'utf-8');
    } catch {
        return null;
    }
}

function buildProblemObject(folder) {
    const folderPath = path.join(problemsDir, folder);
    const problemJsonPath = path.join(folderPath, 'problem.json');
    const problemData = readFileSafe(problemJsonPath);
    if (!problemData) return null;

    const problem = JSON.parse(problemData);
    problem.solutions = {};

    for (const [lang, filename] of Object.entries(solutionFiles)) {
        const code = readFileSafe(path.join(folderPath, filename));
        if (code) {
            problem.solutions[lang] = code;
        }
    }

    // Optionally add README
    const readme = readFileSafe(path.join(folderPath, 'README.md'));
    if (readme) problem.readme = readme;

    return problem;
}

function main() {
    const folders = getProblemFolders(problemsDir);
    const allProblems = [];

    for (const folder of folders) {
        const problemObj = buildProblemObject(folder);
        if (problemObj) allProblems.push(problemObj);
    }

    fs.writeFileSync(outputFile, JSON.stringify(allProblems, null, 2), 'utf-8');
    console.log(`Combined ${allProblems.length} problems into ${outputFile}`);
}

main();