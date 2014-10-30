#include "BsScriptVector2I.h"
#include "BsMonoManager.h"
#include "BsMonoClass.h"
#include "BsMonoUtil.h"

namespace BansheeEngine
{
	ScriptVector2I::ScriptVector2I(MonoObject* instance)
		:ScriptObject(instance)
	{ }

	void ScriptVector2I::initRuntimeData()
	{ }

	MonoObject* ScriptVector2I::box(const Vector2I& value)
	{
		// We're casting away const but it's fine since structs are passed by value anyway
		return mono_value_box(MonoManager::instance().getDomain(), 
			metaData.scriptClass->_getInternalClass(), (void*)&value);
	}

	Vector2I ScriptVector2I::unbox(MonoObject* obj)
	{
		return *(Vector2I*)mono_object_unbox(obj);
	}
}