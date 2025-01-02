#ifndef _SELECTABLE_
#define _SELECTABLE_

#include <memory>
#include <vector>

namespace simple {
	class selectable_group;
	class selectable {
	public:
		selectable() = default;
		selectable(std::string name) :
			name(std::move(name)) {
		}
		const bool& selected() {
			return this->state;
		}
		virtual void selected(bool flag) {
			this->state = flag;
		}
		void set_group(selectable_group* group) {
			this->group = group;
		}
		const std::string& get_name() {
			return this->name;
		}

	protected:
		std::string name;
		selectable_group* group = nullptr;

	private:
		bool state = false;
	};

	class selectable_group {
	public:
		selectable_group(std::vector<std::shared_ptr<selectable>> components) {
			for (const auto& component : components) {
				component->set_group(this);
				this->components.push_back(component);
			}
		}
		void clear() {
			for (const auto& component : this->components) {
				component->selected(false);
			}
		}
		const std::shared_ptr<selectable> selected() {
			for (const auto& component : this->components) {
				if (component->selected()) {
					return component;
				}
			}
			return nullptr;
		}
		bool is_selected() {
			for (const auto& component : this->components) {
				if (component->selected()) {
					return true;
				}
			}
			return false;
		}

	private:
		std::vector<std::shared_ptr<selectable>> components;
	};
}

template<typename... Args>
simple::selectable_group selectable_group(Args... components) {
	return simple::selectable_group(
		{
			std::forward<Args>(components)...
		}
	);
}

#endif // !_SELECTABLE