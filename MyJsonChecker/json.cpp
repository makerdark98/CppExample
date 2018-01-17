//
// Created by lmu on 18. 1. 8.
//

#include "json.h"

Json::Json() {
    this->m_bValid = false;
    this->m_data = false;
    this->m_Changed = false;
}
Json::Json(const std::string &jsonData) {
    this->setData(jsonData);
}

Json::Json(const char *jsonData) {
    this->m_Changed = true;
    this->m_data.assign(jsonData);
}

bool Json::setData(const std::string &jsonData) {
    try {
        if (jsonData.empty()) throw JSON_EMPTY_DATA;
        this->m_Changed = true;
        this->m_data = jsonData;
        return true;
    } catch (JSON_ERROR e) {
        std::cerr << e << std::endl;
        return false;
    }
}

bool Json::setData(const char *jsonData) {
    try {
        if (jsonData == nullptr) throw JSON_EMPTY_DATA;
        this->m_Changed = true;
        this->m_data.assign(jsonData);
    } catch (JSON_ERROR e) {
        std::cerr << e << std::endl;
        return false;
    }
}

bool Json::isValid() {
    if(!this->m_Changed) return this->m_bValid;
    this->m_bValid = Json::checkValid(this->m_data);
    return this->m_bValid;
}


bool Json::checkValid(const std::string &jsonData) {
    std::stack<char> pair;

    for (auto jsonDatum : jsonData) {
        switch (jsonDatum) {
            case '{' :
                pair.push(jsonDatum);
                break;
            case '[':
                if (pair.top() == ':') {
                    pair.push(jsonDatum);
                }
                break;
            case '"':
                if (pair.top() == '"') {
                    pair.pop();
                } else {
                    pair.push(jsonDatum);
                }
                break;
            case ':':
                pair.push(jsonDatum);
                break;
            case ',':
                if (pair.top() == ':') {
                    pair.pop();
                } else {
                    pair.push(jsonDatum);
                }
                break;
            case ']':
                while (pair.top() == ',') {
                    pair.pop();
                }
                if (pair.top() == '[') {
                    pair.pop();
                }
                break;
            case '}':
                if (pair.top() == ':') {
                    pair.pop();
                } else if (pair.top() == '{') {
                    pair.pop();
                }
                break;
            default:
                break;
        }

    }
    return pair.empty();
}

