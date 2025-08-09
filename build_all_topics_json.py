import os
import json
from typing import Dict, List

ROOT = os.path.dirname(os.path.abspath(__file__))
TOPICS_DIR = os.path.join(ROOT, "topics")
OUTPUT_PATH = os.path.join(ROOT, "all_topics.json")


def read_topic_file(topic_dir: str) -> List[dict]:
    path = os.path.join(topic_dir, "problems.json")
    if not os.path.isfile(path):
        return []
    try:
        with open(path, "r", encoding="utf-8") as f:
            data = json.load(f)
            return data if isinstance(data, list) else []
    except Exception:
        return []


def build_all_topics() -> Dict[str, List[dict]]:
    index: Dict[str, List[dict]] = {}
    if not os.path.isdir(TOPICS_DIR):
        return index
    for name in os.listdir(TOPICS_DIR):
        tdir = os.path.join(TOPICS_DIR, name)
        if not os.path.isdir(tdir):
            continue
        problems = read_topic_file(tdir)
        if problems:
            index[name] = problems
    return index


def main():
    index = build_all_topics()
    with open(OUTPUT_PATH, "w", encoding="utf-8") as f:
        json.dump(index, f, indent=2, sort_keys=True)
    print(f"Wrote {OUTPUT_PATH} with {len(index)} topics.")


if __name__ == "__main__":
    main()
