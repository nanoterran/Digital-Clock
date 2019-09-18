#ifndef VIEW_H
#define VIEW_H

#pragma once

class I_View
{
	public:
		virtual ~I_View() {}
		virtual void UpdateView() = 0;
		virtual void ClearView() = 0;
};

#endif /* VIEW_H */