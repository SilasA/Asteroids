#include "Animation.h"

#include "Utilities\Logger.h"

std::string sequence_stos(AnimationState state);

void Animation::AddSequence(AnimSequence& seq)
{
    m_sequences.push_back(seq);
}

void Animation::ChangeSequence(unsigned int seq)
{
    m_curAnim = seq;
    m_log->WriteLog(LogType::kINFO,
        Id(),
        "animation sequence changed: " + sequence_stos((AnimationState)seq),
        "log");
}

Animation::Animation(const std::string& id) :
    Object(id)
{
    m_time = 0.f;
    m_curAnim = -1;
}

Animation::Animation(const std::string& id, sf::IntRect& frameSize) :
    Object(id),
    m_frameSize(frameSize)
{
    m_time = 0.f;
    m_curAnim = -1;
}

Animation::~Animation()
{
}

std::string sequence_stos(AnimationState state)
{
    switch (state)
    {
    case AnimationState::kCreating:
        return "{Creating}";
        break;
    case AnimationState::kNormal:
        return "{Normal}";
        break;
    case AnimationState::kExploding:
        return "{Exploding}";
        break;
    case AnimationState::kExploded:
        return "{Exploded}";
        break;
    default:
        break;
    }
    return "";
}