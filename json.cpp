//
// Created by lmu on 18. 1. 8.
//

#include "json.h"

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

// TODO : implement Json::checkvalid()

bool Json::checkValid(const std::string &jsonData) {
    std::stack<int> s;
}
